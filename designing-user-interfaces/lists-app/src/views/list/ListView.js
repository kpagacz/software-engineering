import React from "react";
import { useParams } from "react-router-dom";
import List from "../../components/list/List.js";
import Navbar from "../../components/navbar/Navbar";
import ShareBar from "../../components/shareBar/ShareBar.js";
import styles from "./ListView.module.css";

const ListView = ({ lists, updateList }) => {
  const { id } = useParams();

  return (
    <div className={styles["listview-container"]}>
      <div>
        <Navbar />
      </div>
      <div>
        <List list={lists[id]} index={id} updateList={updateList} />
      </div>
      <div>
        <ShareBar />
      </div>
    </div>
  );
};

export default ListView;
