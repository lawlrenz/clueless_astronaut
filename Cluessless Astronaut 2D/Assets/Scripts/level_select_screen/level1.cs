using UnityEngine;
using System.Collections;

public class level1 : MonoBehaviour {
	
	private bool mouseOver;

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (mouseOver) {
			if (Input.GetMouseButtonDown(0)){
				Application.LoadLevel(5);
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
