int do_stat(ino_t ino_nr, struct stat *stat)
  stat->st_dev = state.s_dev;
  stat->st_ino = ino_nr;
  stat->st_mode = get_mode(ino, attr.a_mode);
  stat->st_uid = sffs_params->p_uid;
  stat->st_gid = sffs_params->p_gid;
  stat->st_rdev = NO_DEV;
  stat->st_size = attr.a_size;
  stat->st_atimespec = attr.a_atime;
  stat->st_mtimespec = attr.a_mtime;
  stat->st_ctimespec = attr.a_ctime;
  stat->st_birthtimespec = attr.a_crtime;
  stat->st_blocks = stat->st_size / S_BLKSIZE;
  if (stat->st_size % S_BLKSIZE != 0)
	stat->st_blocks += 1;
  stat->st_blksize = BLOCK_SIZE;
  stat->st_nlink = 0;
  if (ino->i_parent != NULL) stat->st_nlink++;
	stat->st_nlink++;
	if (HAS_CHILDREN(ino)) stat->st_nlink++;
  return OK;
int do_chmod(ino_t ino_nr, mode_t *mode)
  if ((ino = find_inode(ino_nr)) == NULL)
  attr.a_mode = *mode; /* no need to convert in this direction */
  *mode = get_mode(ino, attr.a_mode);
int do_utime(ino_t ino_nr, struct timespec *atime, struct timespec *mtime)
  if ((ino = find_inode(ino_nr)) == NULL)
  switch (atime->tv_nsec) {
	atime->tv_nsec = 0;
	attr.a_atime = *atime;

  switch (mtime->tv_nsec) {
	mtime->tv_nsec = 0;
	attr.a_mtime = *mtime;
