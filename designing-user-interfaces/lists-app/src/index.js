import React from "react";
import { createRoot } from "react-dom/client";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import ArchiveView from "./views/archive/ArchiveView.js";
import Home from "./views/home/Home.js";
import ListView from "./views/list/ListView";
import SettingsView from "./views/settings/SettingsView.js";

const App = () => {
  return (
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/list" element={<ListView />} />
      <Route path="/settings" element={<SettingsView />} />
      <Route path="/archive" element={<ArchiveView />} />
    </Routes>
  );
};

const root = createRoot(document.getElementById("root"));
root.render(
  <React.StrictMode>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  </React.StrictMode>
);
