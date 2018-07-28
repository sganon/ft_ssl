if [ -d "libft/" ]; then
  cd libft/
  git stash
  git checkout master
  git pull origin master
else
  git clone https://gitlab.com/sganon/libft.git
fi