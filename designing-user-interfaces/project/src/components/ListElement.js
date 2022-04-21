import React from "react";


const ListElement = (props) => {
  return (
    <div>
      <form>
        <input type="checkbox" checked={props.checked} onChange={props.onCheckboxChange}/>
        <input type="text" onChange={props.onTextChange}></input>
      </form>
    </div>
  );
};

export default ListElement;
