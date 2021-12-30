currentBranch=$(git symbolic-ref --short -q HEAD)

remoteRepo=github_sdk

git tag $1

git tag -d $(git tag)
  
git branch -D main
  
git subtree split --prefix=Plugins --branch main
  
git remote rm $remoteRepo
  
git remote add $remoteRepo git@github.com:xd-platform/XDGSDK-UE4.git

git checkout main --force
  
git fetch --unshallow main
  
git push $remoteRepo main --force --tags
  
git checkout $currentBranch --force
