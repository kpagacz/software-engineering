import React, { useState } from "react";
import { createRoot } from "react-dom/client";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import ArchiveView from "./views/archive/ArchiveView.js";
import Home from "./views/home/Home.js";
import ListView from "./views/list/ListView";
import SettingsView from "./views/settings/SettingsView.js";
import "./index.css";

const App = () => {
  // const list1 = new ToDoList(["Item 1", "Item 2"], [false, false]);
  // const list2 = new ToDoList(["Item 3", "Item 4"], [false, true]);
  // const list3 = new ToDoList(["Item 3", "Item 4"], [false, true]);
  // const list4 = new ToDoList(["Item 3", "Item 4"], [false, true]);
  // list3.archived = true;
  // list4.archived = true;
  // const [lists, setLists] = useState([list1, list2, list3, list4]);
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

  const archiveList = (list) => {
    const index = lists.findIndex((item) => item === list);
    lists[index].archived = true;
    lists[index].archivedAt = new Date();
    updateList(lists[index], index);
  };

  const unArchiveList = (list) => {
    const index = lists.findIndex((item) => item === list);
    lists[index].archived = false;
    updateList(lists[index], index);
  };

  const deleteList = (list) => {
    var filtered = lists.filter((item) => item !== list);
    setLists(filtered);
  };

  return (
    <Routes>
      <Route path="/" element={<Home lists={lists} addList={addList} />} />
      <Route
        path="/lists/:id"
        element={
          <ListView
            lists={lists}
            updateList={updateList}
            archiveList={archiveList}
            deleteList={deleteList}
          />
        }
      />
      <Route path="/settings" element={<SettingsView />} />
      <Route
        path="/archive"
        element={
          <ArchiveView
            lists={lists.filter((list) => list.archived)}
            unArchive={unArchiveList}
          />
        }
      />
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
