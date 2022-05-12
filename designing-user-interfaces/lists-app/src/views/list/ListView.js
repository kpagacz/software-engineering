import React from "react";
import List from "../../components/list/List.js";
import Navbar from "../../components/navbar/Navbar";
import ShareBar from "../../components/shareBar/ShareBar.js";
import styles from "./ListView.module.css";

const Home = () => {
  return (
    <div className={styles["listview-container"]}>
      <div>
        <Navbar />
      </div>
      <div>
        <List />
      </div>
      <div>
        <ShareBar />
      </div>
    </div>
  );
};

export default Home;
