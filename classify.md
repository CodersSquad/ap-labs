Classify API Reference
======================

## Software requirements

- git
- make
- curl
- [jq](https://stedolan.github.io/jq/download/)


Create you account in Classify
------------------------------
```
GITHUB_USER=<your_user> NAME="<your full name>" SCHOOL_ID=<your_school_id> make user
```

**Example:**
```
➜  ap-labs git:(master) ✗ GITHUB_USER=demo NAME="Demo User" SCHOOL_ID="A00123456" make user
curl -k -s -X POST -d "githubID=demo&name=Demo User&schoolID=A00123456" http://localhost:8080/users/ | jq
{
  "message": "Welcome demo to the Classify API.",
  "user": {
    "ID": "89007637-4441-441c-ad6c-3f576aebb36f",
    "Name": "Demo User",
    "GithubID": "demo",
    "SchoolID": "A00123456"
  }
}
```

Verify that your user exists in Classify
----------------------------------------
```
GITHUB_USER=<your_user> make test
```

**Example:**
```
➜  ap-labs git:(master) ✗ GITHUB_USER=demo  make test
User Information
curl -k -s http://localhost:8080/users/\?githubID\=demo  | jq
{
  "message": "List of Users",
  "users": [
    {
      "ID": "89007637-4441-441c-ad6c-3f576aebb36f",
      "Name": "Demo User",
      "GithubID": "demo",
      "SchoolID": "A00123456"
    }
  ]
}
```

Submit a Lab to Classify
------------------------
You can submit your lab's solutions as many times you want **before the lab's due date**. After the due date, it will not be possible to submit any new attempt.

The `make submit` mechanism will submit the `branch` and the `commit` ID of your latest change. It's highly recommend to create a new branch for each lab.

Below an example of the complete flow from pulling to submitting your labs:

1. Pull latest original `ap-labs` content
```
git pull origin master
```

2. Create a new branch for your current lab
```
git checkout -b my-lab-name
cd labs/my-lab-name
```

3. Have fun with your lab and make sure it compiles and runs
```
# Do your best on solving the lab

make

# Test, test and test until you're sure it works as requested.

make clean
```

4. Add, Commit and Push your code
```
git add .
git commit -s -m "Solve my-lab-name"
git push myuser my-lab-name --force
```

5. Submit your work to the Classify API
```
GITHUB_USER=demo make submit
```
