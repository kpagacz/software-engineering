import React from "react";
import { useState } from "react";
import ListElement from "../ListElement";
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
    setChecked([...checked, false]);
    setTexts([...texts, event.target[0].value]);
    event.target[0].value = "";
  };

  const getItemsToDo = () => {
    let checkedCopy = [...checked];
    return (
      <TransitionGroup className="todo-items">
        {checkedCopy.reverse().map((check, index) => {
          if (!check) {
            let reverse_index = checked.length - 1 - index;
            const textHandler = onTextChangeHandler(reverse_index);
            const checkboxHandler = onCheckboxChangeHandler(reverse_index);
            return (
              <CSSTransition
                key={reverse_index}
                timeout={300}
                classNames="todo-item"
              >
                <ListElement
                  onTextChange={textHandler}
                  onCheckboxChange={checkboxHandler}
                  checked={check}
                  text={texts[reverse_index]}
                  key={reverse_index}
                />
              </CSSTransition>
            );
          }
        })}
      </TransitionGroup>
    );
  };

  const getDoneItems = () => {
    let checkedCopy = [...checked];
    return checkedCopy.reverse().map((check, index) => {
      if (check) {
        let reverse_index = checked.length - 1 - index;
        const textHandler = onTextChangeHandler(reverse_index);
        const checkboxHandler = onCheckboxChangeHandler(reverse_index);
        return (
          <ListElement
            onTextChange={textHandler}
            onCheckboxChange={checkboxHandler}
            checked={check}
            text={texts[reverse_index]}
            key={reverse_index}
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
