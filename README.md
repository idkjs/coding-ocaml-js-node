# Running your `javascript` from `dune`

## Checkout other great videos

https://www.youtube.com/c/EduardoRFS

## Brief

The following is a brief introduction on how to start coding in the mess that is the OCaml ecosystem.

You can call me Eduardo and I will be helping you to setup an OCaml environment ... TODO: joke with trying

## Introduction??

### What will you need?

To do that, you will need a couple of tools, they're. The OCaml compiler. A build system. And a language server for VSCode, because no one deserves to code without autocomplete. Everything can be installed through a package manager, so you just get the package manager and that should be it.

For this video we will be using `esy`, an "easy" package manager for OCaml, mostly because it simplifies the life of Windows users a lot.

### Windows Warning

Warning, if you're using windows, I'm sorry for you. Ok, seriously, if you're using windows everything here must be executed as admin, because "windows bad", to run VSCode as admin you need to close all VSCode windows and execute it as admin.

### Installing esy

To install esy, you're going to need the node package manager and git installed. If you have both, you can just put

```sh
npm install --global esy
```

on your terminal.t should take a couple of seconds. But that's it.

## Install project

After that you can just clone my example project on github,

```sh
git clone https://github.com/idkjs/coding-ocaml-js-node.git
```

Enter the folder `/hello`

```sh
cd hello
```

And call `esy`

```sh
esy
```

The first time running `esy` it will install everything that we need, so it will take a couple of minutes, but on subsequent executions everything is cached, so it should be quite fast. On windows it may take a long time and you need to run your VSCode and terminal as an admin.

Add a rule with an alias to the `dune` file to watch the JavaScript output, note the call to `node`. I just took a shot in the dark and it worked. I don't know if there are docs on this:

```sh
(rule
 (alias run_hello_js)
 (deps Hello.bs.js)
 (action
  (run node ./Hello.bs.js)))
```
Add a script to `esy` to watch the `js` output

```json
    "watch-js": "esy b dune build @run_hello_js -w",
```
To check if everything is working, you can call

```sh
esy watch-js
```

If you see `Tu tu ru~ Mayushii desu!`, that means everything is working and we can now setup VSCode.

## VSCode

You should go to your VSCode and install the extension "OCaml Platform". That's it, now you can open the example project on VSCode, open the file `Hello.ml` and you should have everything working, autocomplete, types when you hover some identifier and in-editor typechecking.

## Ending

Yeah, now you can play with OCaml, like a prefessional. If you have any question send a comment below, something something like and subscribe.

## [Redemon File Watcher](https://github.com/ulrikstrid/redemon)

This example use the [redemon](https://github.com/ulrikstrid/redemon) file watcher.

Add `redemon`

```sh
opam pin add redemon https://github.com/ulrikstrid/redemon
```

Try the example from the docs.
Run the following them change `index.js` or create a file and you should see `Hello World!` in the terminal.

```sh
redemon --path=./foo echo "Hello World!"
```

Or pass `node index.js` as a command and see the output
```sh
redemon --path=./foo node foo/index.js
```
