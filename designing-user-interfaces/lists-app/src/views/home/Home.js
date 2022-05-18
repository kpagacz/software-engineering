import React from "react";
import { useNavigate } from "react-router-dom";
import ListPreview from "../../components/listPreview/ListPreview";
import Navbar from "../../components/navbar/Navbar";
import styles from "./Home.module.css";

const Home = ({ lists }) => {
  const navigate = useNavigate();
  const onclickHandler = (index) => {
    return (event) => {
      event.preventDefault();
      navigate("../lists/" + index);
    };
  };
  return (
    <div className={styles["home-container"]}>
      <div>
        <Navbar />
      </div>
      <div className={styles["lists-preview"]}>
        {lists.map((list, index) => (
          <ListPreview key={index} list={list} onclickHandler={onclickHandler(index)} />
        ))}
      </div>
    </div>
  );
};

export default Home;
