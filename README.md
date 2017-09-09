### Basic github workflow

1. Check out develop (if not already):
```
git checkout develop
```

2. Pull the newest version of develop:
```
git remote update && git pull
```

3. Start a local feature branch:
```
git branch <new-feature>
```

4. Checkout this new feature branch:
```
git checkout <new-feature>
```

5. Add/delete/edit files.

6. Stage modifications for commit:
```
git add <files>
```

7. Check status of files staged for commit:
```
git status
```

8. Commit changes:
```
git commit -m "meaningful description of changes"
```

9. Make more changes and repeat process of committing.

10. When ready to merge your branch, push your feature branch to origin for review:
```
git checkout develop
git push origin <feature-branch>
```

11. Make a pull request on github.com and add reviewers appropriately.

12. When branch has been reviewed and merged, delete the branch in origin.

13. Delete old feature branch locally (unless you want to keep it around as a sandbox
```
git branch -D <feature-branch>
```
