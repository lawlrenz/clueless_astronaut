using UnityEngine;
using System.Collections;

public class load_level : MonoBehaviour {

	public int levelID;
	private bool mouseOver;

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (mouseOver) {
			if (Input.GetMouseButtonDown(0)){
				Application.LoadLevel(levelID);
			}
		}
	}
	
	void OnMouseEnter(){
		mouseOver = true;
	}
	
	void OnMouseExit(){
		mouseOver = false;
	}
	
}
