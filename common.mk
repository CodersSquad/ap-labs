# Classify Requirements
SHELL                = bash
GITHUB_USER         ?= demo
CLASSIFY_ENDPOINT   ?= http://classify.obedmr.com
CLASSIFY_TOKEN      ?= demo
CLASSIFY_TOKEN_FILE ?= ${HOME}/.classify_token
CLASS_ID             = 07184303-556d-46ea-ab9d-bd56a9305615
EXECUTABLES          = curl jq

# Common Submission targets
submit: deps check-branch
	@if [[ $$(git ls-files --others --modified --exclude-standard | wc -l) -gt 0 ]]; then \
		echo "You have uncommitted files. Verify them and then, add and commit them."; \
		make clean; \
		git status; \
		exit -1; \
	fi
	@$(eval GITHUB_USER := $(shell git config --local classify.github-user))
	@$(eval CLASSIFY_TOKEN := $(shell git config --local classify.token))
	@$(eval USER_ID := $(shell curl -s -k ${CLASSIFY_ENDPOINT}/users\?githubID\=${GITHUB_USER} | jq -r '.users[0].ID'))
	@$(eval BRANCH := $(shell git rev-parse --abbrev-ref HEAD))
	@$(eval COMMIT_ID := $(shell git log --format='%H' -n 1))
	@$(eval LAB_ID := $(shell curl -s -k ${CLASSIFY_ENDPOINT}/labs\?ClassID\=${CLASS_ID}\&RepoDir=$$(basename "$$PWD") | jq -r '.labs[0].ID'))

	@curl -k -s -X POST -d "branch=$(BRANCH)&commit=$(COMMIT_ID)&token=$(CLASSIFY_TOKEN)&class=$(CLASS_ID)" $(CLASSIFY_ENDPOINT)/labs/$(USER_ID)/${LAB_ID} | jq

check-submission:
	@$(eval GITHUB_USER := $(shell git config --local classify.github-user))
	@$(eval USER_ID := $(shell curl -s -k ${CLASSIFY_ENDPOINT}/users\?githubID\=${GITHUB_USER} | jq -r '.users[0].ID'))
	@$(eval LAB_ID := $(shell curl -s -k ${CLASSIFY_ENDPOINT}/labs\?ClassID\=${CLASS_ID}\&RepoDir=$$(basename "$$PWD") | jq -r '.labs[0].ID'))
	@curl -k -s  $(CLASSIFY_ENDPOINT)/labs/$(USER_ID)/${LAB_ID} | jq

deps:
        $(foreach exec,$(EXECUTABLES),\
         $(if $(shell which $(exec)),,$(error "There's no '$(exec)' binary in your PATH")))

check-branch:
	@if [[ $$(git rev-parse --symbolic-full-name --abbrev-ref HEAD) = "master" ]]; then \
		echo "You cannot make submissions on [master] branch," \
		"please follow Classify API instructions to create a new branch for your lab and then submit your work."; \
		echo "You can check the current branch with the following command:";  \
		echo "> git branch"; \
		exit -1; \
	fi
