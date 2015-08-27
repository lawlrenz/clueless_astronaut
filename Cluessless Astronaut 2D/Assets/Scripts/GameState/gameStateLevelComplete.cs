using UnityEngine;
using System.Collections;

public class gameStateLevelComplete : MonoBehaviour {

	void OnCollisionEnter2D (Collision2D col)
	{
		if (col.gameObject.name == "Player") {
			string actualLevel = Application.loadedLevel + "LevelTime"; //e.g. 3LevelTime
			PlayerPrefs.SetFloat(actualLevel, PlayerPrefs.GetFloat("CurrTime"));
			Application.LoadLevel (1); //back to Menü
		}
	}
}
