using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class gameStateHP : MonoBehaviour {
	public int maxhp;
	Text currHP;

	// Use this for initialization
	void Start () {
		PlayerPrefs.SetInt ("CurrentHP", maxhp);
		currHP = GetComponent<Text> ();

	}
	
	// Update is called once per frame
	void Update () {
		currHP.text = PlayerPrefs.GetInt("CurrentHP").ToString();
	}
}
