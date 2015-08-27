using UnityEngine;
using System.Collections;

public class viewHighScores : MonoBehaviour {

	// Use this for initialization
	void Start () {

		for(int i = 2; i < 3; i++){
			string meshident = "LevelTime" +i;
			string timeident = i + "LevelTime";
			GameObject target = GameObject.Find (meshident);
			TextMesh mesh = (TextMesh) target.GetComponent(typeof(TextMesh));
			
			mesh.text = PlayerPrefs.GetFloat(timeident).ToString("#.00");


		}
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
