import React from "react";
import styles from "./ArchiveView.module.css";
import Navbar from "../../components/navbar/Navbar";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faBoxOpen } from "@fortawesome/free-solid-svg-icons";

const ArchiveView = ({ lists, unArchive }) => {
  const buttonClickHandler = (list) => {
    return (event) => {
      event.preventDefault();
      unArchive(list);
    };
  };
  return (
    <div className={styles["archive-container"]}>
      <Navbar />
      <table>
        <thead>
          <tr>
            <th>List title</th>
            <th>Created At</th>
            <th>Archived At</th>
            <th>Unarchive</th>
          </tr>
        </thead>
        <tbody>
          {lists.map((list, index) => {
            return (
              <tr className={styles.archivedListRow} key={index}>
                <td>{list.title}</td>
                <td>{list.formatDate()}</td>
                <td>{list.formatArchivedAt()}</td>
                <td>
                  <button
                    onClick={buttonClickHandler(list)}
                    className={styles.unArchiveButton}
                    title="Unarchive this list"
                  >
                    <FontAwesomeIcon icon={faBoxOpen} />
                  </button>
                </td>
              </tr>
            );
          })}
        </tbody>
      </table>
    </div>
  );
};

export default ArchiveView;
