using UnityEngine;
using System.Collections;

public class resetHighScores : MonoBehaviour {
	private TextMesh textm;
    private bool mouseOver;
	public int levelamount;
	int sceneoffset = 4;

	// Use this for initialization
	void Start () {
		textm = GetComponent<TextMesh> ();


	}
	
	// Update is called once per frame
	void Update () {
		if (mouseOver) {
			if (Input.GetMouseButtonDown(0)){
				for(int i = 1; i <= levelamount; i++){
					
					int scene_iter = i + sceneoffset;
					string timeident = scene_iter + "LevelTime";
					
					PlayerPrefs.SetFloat(timeident, 999.99f);
				}			
			}
		}
	}
	void OnMouseEnter(){
		if (textm != null) {
			textm.color = new Color (0, 255, 0);
		}
		mouseOver = true;
	}
	
	void OnMouseExit(){
		if (textm != null) {
			textm.color = new Color (255, 255, 255);
		}
		mouseOver = false;
	}

}
