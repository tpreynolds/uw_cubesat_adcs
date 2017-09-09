### Basic github workflow

1. Check out develop (if not already):
```
git checkout develop
```

1. Pull the newest version of develop:
```
git remote update && git pull
```

1. Start a local feature branch:
```
git branch <new-feature>
```

1. Checkout this new feature branch:
```
git checkout <new-feature>
```

1. Add/delete/edit files.

1. Stage modifications for commit:
```
git add <files>
```

1. Check status of files stages for commit:
```
git status
```

1. Commit changes:
```
git commit -m "meaningful description of changes"
```

1. Make more changes and repeat process of committing.

1. When ready to merge your branch, push your feature branch to origin for review:
```
git checkout develop
git push origin <feature-branch>
```

1. Make a pull request on github.com and add reviewers appropriately.

1. When branch has been reviewed and merged, delete the branch in origin.

1. Delete old feature branch locally (unless you want to keep it around as a sandbox
```
git branch -D <feature-branch>
```
