# Default User for testing purposes
NAME		  ?= Demo User
GITHUB_USER       ?= demo
SCHOOL_ID         ?= A00123456
CLASSIFY_ENDPOINT ?= http://classify.obedmr.com/
EXECUTABLES        = curl jq

all: user

deps:
	$(foreach exec,$(EXECUTABLES),\
         $(if $(shell which $(exec)),,$(error "There's no '$(exec)' binary in your PATH")))

user: deps
	curl -k -s -X POST -d "githubID=${GITHUB_USER}&name=${NAME}&schoolID=${SCHOOL_ID}" $(CLASSIFY_ENDPOINT)/users | jq

test: deps
	@echo User Information
	curl -k -s $(CLASSIFY_ENDPOINT)/users\?githubID\=$(GITHUB_USER)  | jq

