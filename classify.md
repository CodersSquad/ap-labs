Classify API - Submission Instructions
======================================

**NOTE:** I'm using  user `obedmr` and lab `lab4.1` for testing purposes. Your real submission should use your github user account in lower case and the proper lab name.

## Software requirements

- git
- curl
- [jq](https://stedolan.github.io/jq/download/) (recommended for easier/readable output)

## Set initial variables
```
export CLASSIFY_API_URL=https://classify-234103.appspot.com
export USER=obedmr
export LAB=lab4.1
```

## Get your Classify API ID
```
userID=$(curl -k $CLASSIFY_API_URL/users/\?githubID\=$USER | jq -r '.users[0].ID')
```

## Get lab ID
```
labID=$(curl $CLASSIFY_API_URL/labs/\?shortName\=$LAB | jq -r '.labs[0].ID')
```

## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" $CLASSIFY_API_URL/labs/$userID/$labID | jq .
```

Expected sample output:
```
{
  "commit": "4b04c22",
  "labID": "2fb40f0d-62ea-4b71-88b1-eee6ca18d60r",
  "message": "Submission Accepted",
  "submissionDate": "Tue Apr  2 14:16:26 2019",
  "userID": "ca83e551-5529-4fc0-971c-161f4f36516a"
}
```


## Check your Lab's submission
```
curl -k $CLASSIFY_API_URL/labs/$userID/$labID | jq .
```

Expected sample output:
```
{
  "message": "Lab's submission data was successfully retrieved",
  "submission": {
    "ID": "61fa9c33-9147-46f1-872a-03f1fc1d1be7",
    "UserID": "ca83e551-5529-4fc0-971c-161f4f36516a",
    "LabID": "2fb40f0d-62ea-4b71-88b1-eee6ca18d60r",
    "CommitID": "4b04c22",
    "Date": "2019-04-02T20:16:26.402621Z"
  },
  "user": "ca83e551-5529-4fc0-971c-161f4f36516a"
}
```