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
	@$(eval GITHUB_USER := $(shell git config --local classify.github-user))
	@$(eval NAME := $(shell git config --local classify.fullname))
	@$(eval SCHOOL_ID := $(shell git config --local classify.school-id))
	curl -k -s -X POST -d "githubID=${GITHUB_USER}&name=${NAME}&schoolID=${SCHOOL_ID}&class=${CLASS_ID}" $(CLASSIFY_ENDPOINT)/users | jq

test: deps
	@echo User Information
	@$(eval GITHUB_USER := $(shell git config --local classify.github-user))
	curl -k -s $(CLASSIFY_ENDPOINT)/users\?githubID\=$(GITHUB_USER)  | jq

submit:
	@echo You cannot submit your lab here. You must be located in the lab directory
	@echo Example:
	@echo cd labs/test-lab
	@echo make submit

check-submission:
	@echo You cannot check your submission here. You must be located in the lab directory
	@echo Example:
	@echo cd labs/test-lab
	@echo make check-submission
