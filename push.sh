#!/bin/bash

# 1. 自动添加所有变更
git add .

# 2. 设置提交信息（包含当前时间）
msg="C语言练习记录 - $(date +'%Y-%m-%d %H:%M:%S')"

# 3. 提交
git commit -m "$msg"

# 4. 推送到远程
git push

echo "✅ 进度已同步到 GitHub！"