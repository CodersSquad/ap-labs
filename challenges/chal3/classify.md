Classify API - Submission Instructions
======================================

**NOTE:** I'm using my user `obedmr` for show casing purposes. Your real submission should use your github user account in lower case.

## Get your Classify API ID
```
curl -k https://classify-234103.appspot.com/users/\?githubID\=obedmr
```
Expected sample output:
```
{"message":"List of Users","users":[{"ID":"ca83e551-5529-4fc0-971c-161f4f36516a","Name":"","GithubID":"obedmr"}]}
```

## Get lab ID
```
curl https://classify-234103.appspot.com/labs/\?shortName\=chal3
```
Expected sample output:
```
{"labs":[{"ID":"2fb40f0d-62ea-4b71-88b1-eee6ca18d60e","Name":"Challenge 3","ShortName":"chal3","Description":"","DueDate":"2019-03-30T05:59:58.041Z"}],"message":"List of Labs"}
```

## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-234103.appspot.com/labs/ca83e551-5529-4fc0-971c-161f4f36516a/2fb40f0d-62ea-4b71-88b1-eee6ca18d60e
```

Expected sample output:
```
{"commit":"7f961e9","labID":"2fb40f0d-62ea-4b71-88b1-eee6ca18d60e","message":"Submission Accepted","submissionDate":"Sat Mar 16 23:56:02 2019","userID":"ca83e551-5529-4fc0-971c-161f4f36516a"}
```


## Check your Lab's submission
```
curl -k https://classify-234103.appspot.com/labs/ca83e551-5529-4fc0-971c-161f4f36516a/2fb40f0d-62ea-4b71-88b1-eee6ca18d60e
```

Expected sample output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"7fd63e1d-b685-44a0-9b0d-ff7d32e1e25d","UserID":"ca83e551-5529-4fc0-971c-161f4f36516a","LabID":"2fb40f0d-62ea-4b71-88b1-eee6ca18d60e","CommitID":"7f961e9","Date":"2019-03-17T05:56:02.416757Z"},"user":"ca83e551-5529-4fc0-971c-161f4f36516a"}
```