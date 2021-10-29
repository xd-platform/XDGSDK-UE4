#!/bin/sh
# 获取当前分支
currentBranch=$(git symbolic-ref --short -q HEAD)


    git tag -d $(git tag)
    
    git branch -D github_upm
    
    git subtree split --prefix=Assets/XD-Intl/"$1" --branch github_upm
    
    git remote rm "$2"
    
    if [ $publish2Release = true ]; then
        echo "start push $2 to git@github.com:XD-Intl/$4-Unity.git"
#        git remote add "$2" git@github.com:XD-Intl/"$4"-Unity.git
    else
        echo "start push $2 to git@github.com:suguiming/$4.git"  
        git remote add "$2" git@github.com:suguiming/"$4".git
    fi;
    
    git checkout github_upm --force
    
    git tag "$3"
    
    git fetch --unshallow github_upm
    
    git push "$2" github_upm --force --tags
    
    git checkout "$currentBranch" --force
    
#    if [ $publish2Release ]; then
#        gh release create "$3" XD-Intl-UnityPackage/XD_Intl_"$1"_"$3".unitypackage -t "$3" -F ./Assets/XD-Intl/"$1"/VERSION_LOG.md -d -R https://github.com/RoongfLee/"$4"-Unity
#    else
#        gh release create "$3" XD-Intl-UnityPackage/XD_Intl_"$1"_"$3".unitypackage -t "$3" -F ./Assets/XD-Intl/"$1"/VERSION_LOG.md -d -R https://github.com/TapTap/"$4"-Unity
#    fi;
    
}
for ((i=0;i<${#upmModule[@]};i++)); do
    publishUPM "${module[$i]}" "${upmModule[$i]}" "$tag" "${githubRepoName[$i]}" 
done