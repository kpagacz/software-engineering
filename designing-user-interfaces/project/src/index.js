import ReactDOM from "react-dom";
import React from "react";
import Home from "./views/Home.js";
import SettingsView from "./views/SettingsView";
import style from "./index.css";

const App = () => {
  return <Home />;
};

ReactDOM.render(<App />, document.getElementById("app"));
