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
git config --local classify.fullname "<Your Full Name>"
git config --local classify.github-user <you_github_user>
git config --local classify.school-id <your_school_id>
make user
```

**Example:**
```
➜  dc-labs git:(master) ✗ git config --local classify.fullname "Demo User"
➜  dc-labs git:(master) ✗ git config --local classify.github-user demo
➜  dc-labs git:(master) ✗ git config --local classify.school-id DEMO1234
➜  dc-labs git:(master) ✗ make user
curl -k -s -X POST -d "githubID=Demo User&name=demo&schoolID=DEMO1234&class=07184303-556d-46ea-ab9d-bd56a9305615" http://localhost:8080/users | jq
{
  "message": "Welcome demo user to the Classify API. Your access token is: 'JDJhJDEwJC5INmZuLy54VmdCeEU1YkRIbDY2ZXVhb0FBclcvMGx5M2hXVkJtWVF1aC9YNG8zUFp6UVo2', save it in the classify.token git local variable",
  "user": {
    "ID": "7ff75fb6-12ce-4e69-a3b0-1104bd9ce790",
    "Name": "demo",
    "GithubID": "demo user",
    "SchoolID": "DEMO1234",
    "ClassID": "07184303-556d-46ea-ab9d-bd56a9305615"
  }
}
```

**Don't forget to save your token into the git local configuration**
```
git config --local classify.token <your_assigned_very_long_token>
```

*Example*
```
git config --local classify.token JDJhJDEwJC5INmZuLy54VmdCeEU1YkRIbDY2ZXVhb0FBclcvMGx5M2hXVkJtWVF1aC9YNG8zUFp6UVo2
```


Verify that your user exists in Classify
----------------------------------------
```
make test
```

**Example:**
```
➜  ap-labs git:(master) ✗ make test
User Information
curl -k -s http://localhost:8080/users/\?githubID\=demo  | jq
{
  "message": "List of Users",
  "users": [
    {
      "ID": "7ff75fb6-12ce-4e69-a3b0-1104bd9ce790",
      "Name": "Demo User",
      "GithubID": "demo",
      "SchoolID": "DEMO1234"
    }
  ]
}
```

Submit a Lab to Classify
------------------------
You can submit your lab's solutions as many times you want **before the lab's due date**. After the due date, it will not be possible to submit any new attempt.

The `make submit` mechanism will submit the `branch` and the `commit` ID of your latest change. It's highly recommend to create a new branch for each lab.

Below an example of the complete flow from pulling to submitting your labs:

0. Checkout into the master branch
```
git checkout master
```

1. Pull latest original `ap-labs` content. This will synchronize with the original class repository.
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
```

4. Once you are done with your code: add, commit and push your code to your remote personal copy (fork) of the original repository.
```
git add .
git commit -s -m "Solve my-lab-name"
git push myuser my-lab-name
```

5. Submit your work to the Classify API. This will notify the professor that your work has been completed.
Change the `demo` user to your github user account.
```
make submit
```

6. Verify that your work is properly submitted to the Classify API
```
make check-submission
```