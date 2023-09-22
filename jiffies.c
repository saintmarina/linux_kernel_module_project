/**
 * jiffies.c
 *
 * Kernel module that communicates with /proc file system.
 *
 * This module reports the current value of jiffies when the /proc/jiffies file is read.
 *
 * Operating System Concepts - 10th Edidtion
 * Chapter 2, Programming projects, IV Assignments, 1.
 *
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 256
#define PROC_NAME "jiffies"

static ssize_t proc_read(struct file *file, char *buf, size_t count, loff_t *pos);

static struct proc_ops my_proc_ops = {
	.proc_read = proc_read,
};

static int proc_init(void)
{
	proc_create(PROC_NAME, 0, NULL, &my_proc_ops);
	printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
	return 0;
}

static void proc_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
	printk( KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;

	if (completed) {
		completed = 0;
		return 0;
	}

	completed = 1;
	rv = sprintf(buffer, "Current value of jiffies = %ld\n", jiffies);
	copy_to_user(usr_buf, buffer, rv);
	return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Jiffies Module");
MODULE_AUTHOR("SGG");
