const path = require("path");

module.exports = {
  entry: "./src/floating-island.js",
  output: {
    filename: "main.js",
    path: path.resolve(__dirname, "dist"),
  },
  watch: true,
};
