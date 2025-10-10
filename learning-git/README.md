# Agenda

- [Agenda](#agenda)
- [Version Control Systems (VCS)](#version-control-systems-vcs)
	- [Centralized Version Control Systems](#centralized-version-control-systems)
	- [Distributed Version Control Systems](#distributed-version-control-systems)
- [What is Git?](#what-is-git)
- [How Git Works](#how-git-works)
- [Git Setup \& Important Git commands](#git-setup--important-git-commands)
- [Visualizing Git](#visualizing-git)
- [Resources](#resources)

# Version Control Systems (VCS)

- **Track Changes:** 
	- Helps developers manage changes to source code over time. 
	- Records every modification made to the codebase. 
- **Collaboration:** 
	- Helps multiple developers to work on the same project simultaneously without overwriting each other’s work.
	- Important because code development is not a linear process.
- **History and Reversion:** 
	- Maintains history of changes, allowing developers to revert to previous versions if needed.
## Centralized Version Control Systems

![CVCS diagram](../Media/CVCS.png)
- **Single Central Repository:** All users work with a single central repository, typically hosted on a server.
- **Commit and Update:** Developers commit their changes to this central repository and update their local copies to stay in sync with others.
- **Pro:** 
	- Simplified Management - Since all changes are tracked in a single central repository, it’s easier to manage and control the code base.
- **Con:** 
	- Single Point of Failure - If the central server goes down or becomes inaccessible, no one can commit changes or access the latest version of the code.
## Distributed Version Control Systems

![DVCS diagram](../Media/DVCS.png)
- **Local Repositories:** Each developer has a complete copy of the repository, including the full history of changes.
- **Peer-to-Peer:** Changes are shared between repositories, allowing for more flexible workflows and offline work.
- **Pro:** 
	- Enhanced Collaboration - Each developer has a full copy of the repository, allowing for more flexible workflows, offline work, and easier branching and merging.
- **Con:** 
	- Complexity - Managing multiple copies of the repository and coordinating changes between them can be more complex and require more sophisticated tools and practices.
# What is Git?

- Git is a **popular**, **free**, and **open-source** **Distributed Version Control System**!
	- Collaboration
	- Version History
	- Backup and Recovery
	- Offline Work
	- Conflict Resolution

> [!NOTE] Git is everywhere!
> According to the [Stack Overflow Developer Survey 2022](https://survey.stackoverflow.co/2022/#section-version-control-version-control-systems), 95% of developers reported Git as their primary version control system.

# How Git Works

1. **Local Repository**: You have a repository on your local machine where you keep your files. This is your personal workspace where you make changes and save versions of your files.
2. **Remote Repository**: There’s also a repository on a server (like GitHub, GitLab, or Bitbucket). This acts as a central hub where you can store your files and share them with others.
3. **Synchronization**: You can synchronize your local repository with the remote one. This means you can upload your changes to the server (push) and download changes from the server (pull).
4. **Collaboration**: If you’re working with others, they can also upload their changes to the remote repository. You can then download these changes to your local repository.

# Git Setup & Important Git commands

1. Install Git
	1. Download and install Git from [git-scm](https://git-scm.com/).
	2. Verify installation by running the command below in your terminal:
		```shell
		git --version   
		```
2. Configure Git
	1. Set your username and email:
		```shell
		git config --global user.name "Your Name"
		git config --global user.email "your.email@example.com"
		```
3. Initialize a Repository
	1. Navigate to your project directory and initialize Git:
		```shell
		cd /path/to/your/project
		git init
		```
4. Check status
	```shell
	git status
	```
5. Add Git Ignore (optional)
6. Stage changed files
	```shell
	git add filename
	```
7. Commit staged files
	```shell
	git commit -m "Your commit message"
	```
8. Create a Remote Repository
	1. Create a repository on a platform like GitHub.
	2. Link your local repo to the remote repo: 
		```shell
		git remote add origin https://github.com/yourusername/your-repo.git
		```
9. Push changes to the Remote Repository
	1. Push your changes: 
		```shell
		git push -u origin master
		```

	> [!NOTE] Git Forks
	> - The `-u` (same as `--set-upstream`) in `git push` is used to set the fork to be used. In the previous command, `origin` is the name of the fork and `master` is the name of the branch.
	>
	> - What are Git Forks?
	> 	- Independent Copies: A Git fork is a complete copy of a repository that exists independently from the original.
	> 	- Separate Development: It allows developers to work on their own version of the project without affecting the original repository.
	> 	- Branches: Each fork can have its own branches, enabling multiple lines of development.
	>
	> - Why are Git Forks Used?
	> 	- Experimentation: Developers can test new features or changes in their own fork without risking the stability of the main project.
	> 	- Collaboration: Forks enable multiple developers to work on the same project simultaneously, _each in their own space_, before merging changes back into the original repository.

10. Pull Changes from the Remote Repository
	```shell
	git pull origin master
	```
11. Branching
	1. Create a new branch
		```shell
		git branch new-branch  
		```
	2. Checkout (switch) to the new or an existing branch
		```shell
		git checkout new-branch
		```
12. Merge Branches
	1. Switch to the main branch
		```shell
		git checkout master
		```
	2. Merge the new branch into the main branch
	   ```shell
		git merge new-branch
		```
13. View Commit History
	```shell
	git log
	```
14. Cloning an existing Repository
	```shell
	git clone https://github.com/yourusername/your-repo.git
	```

	> [!NOTE] Git Submodules
	> - Git submodules are a way to include one Git repository inside another as a subdirectory. This allows you to keep a separate project within your main project while maintaining its own version control. 
	> - To clone a Git Repo with Submodules:
	> ```shell 
	> git clone --recurse-submodules https://github.com/yourusername/your-repo.git
	> ```
15. Git Merge
    1. Switch to the branch you want to merge into
        ```shell
        git checkout master
        ```
    2. Merge the feature branch into the master branch
        ```shell
        git merge feature-branch
        ```

    > [!NOTE] Better Practice: Use Pull (Merge) Requests
    > - **Code Review:** Pull requests give other developers a chance to review the code before merging.
    > - **Discussion:** They provide a platform for discussing changes and suggesting improvements.
    > - **Testing:** Ensures that the code passes all tests and meets the project's standards before being merged. (CI/CD)
    > - **Documentation:** Pull requests serve as documentation for why changes were made and how they were implemented.


# Visualizing Git

[Visualizing Git Concepts with D3](https://onlywei.github.io/explain-git-with-d3/)

# Resources

1. [Centralized vs Distributed Version Control Systems | Medium](https://faun.pub/centralized-vs-distributed-version-control-systems-a135091299f0)
2. [A Simple Introduction to Git | CS 5010 | Northeastern University](https://course.ccs.neu.edu/cs5010f15/Slides/Lesson%200.5%20Introduction%20to%20Git.pptx)
3. [Stack Overflow Developer Survey 2022](https://survey.stackoverflow.co/2022/#section-version-control-version-control-systems)
