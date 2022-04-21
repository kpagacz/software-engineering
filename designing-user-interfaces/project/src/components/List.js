import React from "react";
import { useState } from "react/cjs/react.production.min";
import ListElement from "./ListElement";

const List = () => {
  // const [checked, setChecked] = useState([]);
  // const [texts, setTexts] = useState([]);

  const onCheckboxChangeHandler = () => {
    console.log("checkbox clicked");
  };

  const onTextChangeHandler = (event) => {
    console.log(event.target.value);
  };

  const newListHandler = (event) => {
    event.preventDefault();
    console.dir(event.target[0].value);
  }

  return (
    <div>
      <form onSubmit={newListHandler}>
        <input type="text" placeholder="Add another item..."></input>
      </form>
      <ListElement
        onTextChange={onTextChangeHandler}
        onCheckboxChange={onCheckboxChangeHandler}
      />
    </div>
  );
};

export default List;
