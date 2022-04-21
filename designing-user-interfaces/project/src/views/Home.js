import React from "react";
import List from "../components/List.js";
import ListElement from "../components/ListElement.js";

export default () => {
  const onCheckboxChangeHandler = () => {
    console.log("checkbox clicked");
  };

  const onTextChangeHandler = (event) => {
    console.log(event.target.value);
  };
  return (
    <div>
      <div>Lists Overview</div>
      <List />
    </div>
  );
};
