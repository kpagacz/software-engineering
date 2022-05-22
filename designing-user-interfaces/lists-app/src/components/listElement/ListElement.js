import React, { useEffect, useRef } from "react";
import styles from "./ListElement.module.css";

const ListElement = ({
  checked,
  text,
  onCheckboxChange,
  onTextChange,
  readOnly,
  className,
}) => {
  const textInput = useRef(null);

  useEffect(() => {
    textInput.current.innerText = text;
  }, []);

  return (
    <form
      onSubmit={(e) => e.preventDefault()}
      className={className == null ? styles["form-default-style"] : className}
    >
      <input
        type="checkbox"
        checked={checked}
        onChange={onCheckboxChange}
        readOnly={readOnly}
        className={styles["list-element-checkbox"]}
      />
      <div
        ref={textInput}
        onInput={onTextChange}
        className={
          checked
            ? styles["list-element-text-input--strikethrough"]
            : styles["list-element-text-input"]
        }
        contentEditable={true}
        suppressContentEditableWarning={true}
      />
    </form>
  );
};

export default ListElement;
