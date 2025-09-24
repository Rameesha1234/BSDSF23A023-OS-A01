#!/bin/bash

# Navigate into your repo first
# cd BSDSF23A023-OS-A01

# Start date (31 days ago)
start_date=$(date -d "31 days ago" +"%Y-%m-%d")

for i in {1..31}
do
  commit_date=$(date -d "$start_date + $i days" +"%Y-%m-%d 10:00:00")

  echo "Commit $i on $commit_date" >> progress.txt
  git add progress.txt
  GIT_COMMITTER_DATE="$commit_date" git commit --date "$commit_date" -m "Commit $i"
done

git push origin main --force
