using UnityEngine;
using System.Collections;

public class Controls : MonoBehaviour {
	
	private bool mouseOver;
	
	private TextMesh textm;
	// Use this for initialization
	void Start () {
		textm = GetComponent<TextMesh> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (mouseOver) {
			if (Input.GetMouseButtonDown(0)){
				Application.LoadLevel(4);
			}
		}
	}
	
	void OnMouseEnter(){
		textm.color = new Color (0, 0, 0);
		mouseOver = true;
	}
	
	void OnMouseExit(){
		textm.color = new Color (255, 255, 255);
		mouseOver = false;
	}
	
}
