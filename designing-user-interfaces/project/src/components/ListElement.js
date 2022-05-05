import React from "react";

const ListElement = ({
  checked,
  text,
  onCheckboxChange,
  onTextChange,
  readOnly,
}) => {
  return (
    <form onSubmit={(e) => e.preventDefault()}>
      <input type="checkbox" checked={checked} onChange={onCheckboxChange} />
      <input type="text" value={text} onChange={onTextChange} readOnly={readOnly}/>
    </form>
  );
};

export default ListElement;
