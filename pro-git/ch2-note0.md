git config --global user.name plus7wist
git config --global user.email gu\_castle@163.com
git config --global core.editor vim
git config --global diff.tool vimdiff

W: 工作区 working directory
S: 暂存区 Staging area
R: 仓库区 Repository(git directory)

git diff # W 和 S 比较
git diff --cached # S 和 R 比（R 的最后一次提交）

git rm code.cc # 删除 WS 里的
git rm --cached code.cc # 删除 S 里的


## undo

```
# 如果你忘记 add 某个文件即进行了提交
git commit -m 'initial commit'
git add one-forgotten-file
git commit --amend

# 如果你提交信息写错了
git commit -m 'initil commit' # typo
git commit --amend

# 回退 S 中的更改：回退 git add code.cc 命令
git reset HEAD code.cc

# 回退 W 中的更改：这个命令可能比较危险
git checkout -- code.cc
```

## 远程仓库（remote）

```
git clone [url]
# 克隆的同时，本地仓库也出现了一个远程仓库 origin

git remote -v
# 显示远程仓库
# v 表示 verbose，也显示远程仓库的链接

# 先在远程创建仓库
git remote add remote-flag url-of-remote-repo

git fetch remote-flag
# 创建一个分支，把 remote-flag 里的内容取下来
```