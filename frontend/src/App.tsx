import { FileDoneOutlined } from "@ant-design/icons";
import { Tag } from "antd";
import classNames from "classnames";

import styles from "./App.module.scss";

interface Item {
  id: number;
  difficulty: "Easy" | "Medium" | "Hard";
  topic: "Algorithm" | "DataBase";
  title: string;
  description: string;
  labels: string[];
}

const items: Item[] = [
  {
    id: 1,
    difficulty: "Easy",
    topic: "Algorithm",
    title: "Two Sum",
    description: "",
    labels: ["Hash Map", "Link List"],
  },
  {
    id: 2,
    difficulty: "Medium",
    topic: "Algorithm",
    title: "Add Two Numbers",
    description: "",
    labels: [],
  },
];

function App() {
  return (
    <div className={styles.container}>
      <div className={styles.title}>Valhalla</div>
      <div className={styles.subtitle}>
        Valhalla of coder, collections of solutions of LeetCode problems.
      </div>
      <div className={styles.langs}>
        <a>
          <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/rust/rust-plain.svg" />
        </a>
        <a>
          <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" />
        </a>
      </div>
      <div className={styles["items-header"]}>
        <div style={{ flex: 0.5, position: "relative", left: "1rem" }}>ID</div>
        <div style={{ flex: 4 }}>Title</div>
        <div style={{ flex: 1 }}>Solution</div>
        <div style={{ flex: 1 }}>Difficulty</div>
        <div style={{ flex: 1 }}>Topic</div>
        <div style={{ flex: 2 }}>Labels</div>
      </div>
      <div className={styles["items-container"]}>
        {items.map((item, key) => (
          <div
            key={key}
            className={classNames(styles.item, {
              [styles["item-double"]]: key % 2 !== 0,
            })}
          >
            <div className={styles.id}>{item.id}</div>
            <div className={styles["problem-title"]}>{item.title}</div>
            <div className={styles.solution}>
              <a href="https://github.com/SKTT1Ryze/Valhalla">
                <FileDoneOutlined />
              </a>
            </div>
            <div
              className={classNames(styles["problem-difficulty"], {
                [styles.easy]: item.difficulty === "Easy",
                [styles.medium]: item.difficulty === "Medium",
                [styles.hard]: item.difficulty === "Hard",
              })}
            >
              {item.difficulty}
            </div>
            <div className={styles.topic}>{item.topic}</div>
            <div className={styles.labels}>
              {item.labels.map((label) => (
                <Tag bordered className={styles.tag}>
                  {label}
                </Tag>
              ))}
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}

export default App;
