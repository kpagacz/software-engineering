import React from "react";
import { useState } from "react";
import ListElement from "./ListElement";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faArrowRight } from "@fortawesome/free-solid-svg-icons";
import { CSSTransition, TransitionGroup } from "react-transition-group";

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
    setChecked([false, ...checked]);
    setTexts([event.target[0].value, ...texts]);
    event.target[0].value = "";
  };

  const getItemsToDo = () => {
    return (
      <TransitionGroup className="todo-items">
        {checked.map((check, index) => {
          if (!check) {
            const textHandler = onTextChangeHandler(index);
            const checkboxHandler = onCheckboxChangeHandler(index);
            return (
              <CSSTransition key={index} timeout={300} classNames="todo-item">
                <ListElement
                  onTextChange={textHandler}
                  onCheckboxChange={checkboxHandler}
                  checked={check}
                  text={texts[index]}
                  key={index}
                />
              </CSSTransition>
            );
          }
        })}
      </TransitionGroup>
    );
  };

  const getDoneItems = () => {
    return checked.map((check, index) => {
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
    });
  };

  return (
    <div>
      <form onSubmit={newListHandler}>
        <input
          type="text"
          placeholder="Add another item..."
          autoFocus
          required="required"
        ></input>
        <button type="submit">
          <FontAwesomeIcon icon={faArrowRight} />
        </button>
      </form>
      {getItemsToDo()}
      {checked.some((value) => value === true) && <div>Done:</div>}
      {getDoneItems()}
    </div>
  );
};

export default List;
