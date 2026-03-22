#!/bin/bash

# 1. 确保我们在仓库根目录下
cd ~/C_Learning

# 2. 检查是否有任何变动（包括新文件、修改、删除）
# -A 代表 All，它会捕捉整个文件夹内所有的蛛丝马迹
git add -A

# 3. 检查是否有东西需要提交，防止空跑报错
if git diff-index --quiet HEAD --; then
    echo "--- 文件夹内没有发现任何新变动，无需上传 ---"
    exit
fi

# 4. 获取当前日期时间
current_date=$(date "+%Y-%m-%d %H:%M")

echo "🚀 正在全量同步 ~/C_Learning 到 GitHub..."

# 5. 提交并推送到云端
git commit -m "Full Sync: $current_date (Automated Upload)"
git push origin main

echo "✅ 同步成功！你所有的代码和笔记都已安全上云。"
