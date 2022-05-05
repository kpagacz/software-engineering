import ReactDOM from "react-dom";
import React from "react";
import Home from "./views/Home.js";
import SettingsView from "./views/SettingsView";
import List from "./components/List";
import style from "./index.css";

const App = () => {
  return <List />;
};

ReactDOM.render(<App />, document.getElementById("app"));
