# prefab.g8
Setup an app + server easily

### Why?

We wanted to make it easy for anyone to set up a new repo for building a phone app.

## Usage
1. `git clone https://github.com-keystrok:keystrok/prefab.g8.git` 
1. `g8 file://prefab.g8` (or `g8 file://prefab.g8 --name=my project` to accept all defaults)
1. `cd {project name}`
1. `./init.sh`
1. That's it!

Your projects will be generated inside this folder, e.g. app and server should be opened in intellij as separate projects.
Alternatively, if you want to open all the projects in one intellij window, you can open the root and then select:
```file -> new -> Module from exsiting sources``` and select server for example
