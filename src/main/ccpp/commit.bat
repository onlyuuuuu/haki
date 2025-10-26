@ECHO OFF

git config user.email "duyanhnn@outlook.com"
git config user.name "Andy"

git pull --rebase
git add .
git commit -m "commit"
git push
