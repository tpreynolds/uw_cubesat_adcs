### Basic github workflow

Checkout the develop (if not already)
```
git checkout develop
```

Pull the newest version of develop
```
git remote update && git pull
```

Start a local feature branch
```
git branch <new-feature>
```

Checkout new feature branch
```
git checkout <new-feature>
```

Add/delete/edit files

Stage modifications for commit
```
git add <files>
```

Check status of files stages for commit
```
git status
```

Commit changes
```
git commit -m "meaningful description of changes"
```

Make more changes and repeat process of committing

When ready to commit feature branch to develop
```
git checkout develop
git merge <feature-branch>
```

Delete old feature branch (unless you want to keep it around as a sandbox
```
git branch -d <feature-branch>
```

Push local develop to remote
```
git push
```
