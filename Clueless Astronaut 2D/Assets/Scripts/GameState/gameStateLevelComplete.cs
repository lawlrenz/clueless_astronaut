using UnityEngine;
using System.Collections;

public class gameStateLevelComplete : MonoBehaviour {

	public int reloadID;


	void Update(){
		if (Input.GetButton ("Fire3")) {
			Application.LoadLevel(reloadID);
		}
	}
	void OnCollisionEnter2D (Collision2D col)
	{
		if (col.gameObject.name == "Player") {
			string actualLevel = Application.loadedLevel + "LevelTime"; //e.g. 3LevelTime
			float oldtime = PlayerPrefs.GetFloat(actualLevel);
			float newtime = PlayerPrefs.GetFloat("CurrTime");

			if(oldtime == 0  || newtime < oldtime){
				PlayerPrefs.SetFloat(actualLevel, newtime);
			}
			Application.LoadLevel (1); //back to Menü
		}
	}
}
