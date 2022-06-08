import React from "react";
import { useNavigate } from "react-router-dom";
import AddList from "../../components/addList/AddList";
import ListPreview from "../../components/listPreview/ListPreview";
import Navbar from "../../components/navbar/Navbar";
import styles from "./Home.module.css";

const Home = ({ lists, addList }) => {
  const navigate = useNavigate();

  const onPreviewClickHandler = (index) => {
    return (event) => {
      event.preventDefault();
      navigate("../lists/" + index);
    };
  };

  return (
    <div className={styles["home-container"]}>
      <Navbar />
      <div>
        <AddList addList={addList} />
        <div className={styles["list-previews-container"]}>
          {lists.map((list, index) => {
            if (!list.archived)
              return (
                <ListPreview
                  key={index}
                  list={list}
                  onclickHandler={onPreviewClickHandler(index)}
                />
              );
          })}
        </div>
      </div>
    </div>
  );
};

export default Home;
