import React from "react";

const ListPreview = ({ list, onclickHandler }) => {
  return (
    <div onClick={onclickHandler}>
      List preview. Elements no: {list.items.length}
    </div>
  );
};

export default ListPreview;
