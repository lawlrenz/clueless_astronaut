using UnityEngine;
using System.Collections;

public class viewHighScores : MonoBehaviour {
	public int levelamount;
	int sceneoffset = 4;

	// Use this for initialization
	void Start () {

		for(int i = 1; i <= levelamount; i++){
			string meshident = "LevelTime" +i ;
			int scene_iter = i + sceneoffset;
			string timeident = scene_iter + "LevelTime";

			GameObject target = GameObject.Find (meshident);
			TextMesh mesh = (TextMesh) target.GetComponent(typeof(TextMesh));
			mesh.text = PlayerPrefs.GetFloat(timeident).ToString("#.00");
		}
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
