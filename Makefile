# Default User for testing purposes
NAME		  ?= Demo User
GITHUB_USER       ?= demo
SCHOOL_ID         ?= A00123456
CLASSIFY_ENDPOINT ?= http://classify.obedmr.com/
CLASS_ID           = 07184303-556d-46ea-ab9d-bd56a9305610
EXECUTABLES        = curl jq

all: user

deps:
	$(foreach exec,$(EXECUTABLES),\
         $(if $(shell which $(exec)),,$(error "There's no '$(exec)' binary in your PATH")))

user: deps
	curl -k -s -X POST -d "githubID=${GITHUB_USER}&name=${NAME}&schoolID=${SCHOOL_ID}&class=${CLASS_ID}" $(CLASSIFY_ENDPOINT)/users | jq

test: deps
	@echo User Information
	curl -k -s $(CLASSIFY_ENDPOINT)/users\?githubID\=$(GITHUB_USER)  | jq

submit:
	@echo Cannot submit your lab. You must be located in the lab directory
	@echo Example:
	@echo cd labs/first-challenge
	@echo GITHUB_USER=demo make submit

check-submission:
	@echo Cannot check your submission. You must be located in the lab directory
	@echo Example:
	@echo cd labs/first-challenge
	@echo GITHUB_USER=demo make check-submission
