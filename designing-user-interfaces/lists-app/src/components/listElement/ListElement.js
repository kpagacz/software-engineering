import React from "react";

const ListElement = (props) => {
  const { checked, text, onCheckboxChange, onTextChange, readOnly } = props;
  return (
    <form onSubmit={(e) => e.preventDefault()}>
      <input type="checkbox" checked={checked} onChange={onCheckboxChange} />
      <input
        type="text"
        value={text}
        onChange={onTextChange}
        readOnly={readOnly}
      />
    </form>
  );
};

export default ListElement;
