using UnityEngine;
using System.Collections;

public class viewHighScores : MonoBehaviour {
	public int levelamount;
	int sceneoffset = 4;

	// Use this for initialization
	void Start () {
		GameObject scoreboard = GameObject.Find ("scoreboard");
		TextMesh scoreboard_mesh = (TextMesh) scoreboard.GetComponent(typeof(TextMesh));

		for(int i = 1; i <= levelamount; i++){

			int scene_iter = i + sceneoffset;
			string timeident = scene_iter + "LevelTime";

			scoreboard_mesh.text += "\n#" + i + " - " + PlayerPrefs.GetFloat(timeident).ToString("#.00");
		}
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
