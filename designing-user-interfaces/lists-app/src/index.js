import React, { useEffect, useState } from "react";
import { createRoot } from "react-dom/client";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import ToDoList from "./models/ToDoList.js";
import ArchiveView from "./views/archive/ArchiveView.js";
import Home from "./views/home/Home.js";
import ListView from "./views/list/ListView";
import SettingsView from "./views/settings/SettingsView.js";
import "./index.css";

const App = () => {
  const [lists, setLists] = useState([]);

  const updateList = (newList, index) => {
    const newLists = lists.map((list, id) => {
      if (parseInt(index) !== parseInt(id)) return list;
      else return newList;
    });
    setLists(newLists);
  };

  const addList = (list) => {
    setLists([...lists, list]);
    // setTimeout(() => navigate("../lists/" + lists.length - 1, {replace: true}), 500);
  };

  useEffect(() => {
    const list1 = new ToDoList(["Item 1", "Item 2"], [false, false]);
    const list2 = new ToDoList(["Item 3", "Item 4"], [false, true]);
    setLists([...lists, list1, list2]);
  }, []);

  return (
    <Routes>
      <Route
        path="/"
        element={
          <Home
            lists={lists.filter((list) => !list.archived)}
            addList={addList}
          />
        }
      />
      <Route
        path="/lists/:id"
        element={<ListView lists={lists} updateList={updateList} />}
      />
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
