import React from "react";
import { useState } from "react";
import ListElement from "./ListElement";

const List = () => {
  const [checked, setChecked] = useState([]);
  const [texts, setTexts] = useState([]);

  const onCheckboxChangeHandler = (index) => {
    return () => {
      setChecked(updateList(checked, index, !checked[index]));
    };
  };

  const updateList = (list, index, value) => {
    const copy = [...list];
    copy[index] = value;
    return copy;
  };

  const onTextChangeHandler = (index) => {
    return (event) => {
      setTexts(updateList(texts, index, event.target.value));
    };
  };

  const newListHandler = (event) => {
    event.preventDefault();
    console.dir(event.target[0].value);
    setChecked([false, ...checked]);
    setTexts([event.target[0].value, ...texts]);
    event.target[0].value = "";
  };

  return (
    <div>
      <form onSubmit={newListHandler}>
        <input type="text" placeholder="Add another item..." autofocus></input>
      </form>
      {checked.map((check, index) => {
        if (!check) {
          const textHandler = onTextChangeHandler(index);
          const checkboxHandler = onCheckboxChangeHandler(index);
          return (
            <ListElement
              onTextChange={textHandler}
              onCheckboxChange={checkboxHandler}
              checked={check}
              text={texts[index]}
              key={index}
            />
          );
        }
      })}
      {checked.some((value) => value === true) && <div>Done:</div>}
      {checked.map((check, index) => {
        if (check) {
          const textHandler = onTextChangeHandler(index);
          const checkboxHandler = onCheckboxChangeHandler(index);
          return (
            <ListElement
              onTextChange={textHandler}
              onCheckboxChange={checkboxHandler}
              checked={check}
              text={texts[index]}
              key={index}
              readOnly="readonly"
            />
          );
        }
      })}
    </div>
  );
};

export default List;
