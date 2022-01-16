# Floating island
<p align="center">
  <img src="https://github.com/kpagacz/software-engineering/blob/main/grafika-komputerowa/project/images/island.png" />
</p>
## Introduction
This work was done as part of the Computer Graphics course during 3rd year of my Computer Science Bachelor's Degree.

## Installation
### Requirements
* Node Package Manager 6.14 (instructions on how to install available [here](https://docs.npmjs.com/downloading-and-installing-node-js-and-npm))

I sincerely recommend using [nvm](https://github.com/nvm-sh/nvm) to manage Node and Node Package Manager installations.

### Building
If need be the sources in this directory can be rebuild. I used the `webpack` module to bundle all the resources. The output is stored in the `main.js` file in the `dist` directory.
To rebuild, navigate to this directory and run:
```
npm run build
```
The default webpack configuration is set to watch any changes to the source files.

### Running
Open `dist/project.html` in a browser. I have used Firefox v96.0.1 to test this project but it should run on Google Chrome as well.
