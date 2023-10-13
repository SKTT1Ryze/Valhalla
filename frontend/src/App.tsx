import styles from "./App.module.scss";

interface Item {
  id: number;
  difficulty: string;
  topic: string;
  title: string;
  description: string;
  labels: string[];
}

const items: Item[] = [
  {
    id: 1,
    difficulty: "",
    topic: "",
    title: "Two Numbers",
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
      {items.map((item) => (
        <div>{item.title}</div>
      ))}
    </div>
  );
}

export default App;
